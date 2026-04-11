#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    // printf("%s %s\n", candidates[0].name, candidates[1].name);
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        // printf("%i %i %i\n", candidates[0].votes, candidates[1].votes, candidates[2].votes);
        printf("\n");
    }
    // printf("%i %i vote \n", candidates[0].votes, candidates[1].votes);
    // printf("%s %s vote\n", candidates[0].name, candidates[1].name);
    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        // printf("%i\n", preferences[0][0]);
        tabulate();
        // printf("%i\n", preferences[0][0]);
        // printf("%i %i tabulate \n", candidates[0].votes, candidates[1].votes);
        // Check if election has been won
        // printf("%i\n", preferences[0][0]);
        bool won = print_winner();
        if (won)
        {
            break;
        }
        // printf("%s %s won\n", candidates[0].name, candidates[1].name);
        // printf("%i\n", preferences[0][0]);
        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);
        // printf("%s %s tie \n", candidates[0].name, candidates[1].name);
        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                // printf("%s %s\n", candidates[0].name, candidates[1].name);
                if (candidates[i].eliminated == false)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // if (rank == 0)
            // candidates[i].votes += 1;
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (!candidates[preferences[i][j]].eliminated)
            {
                candidates[preferences[i][j]].votes += 1;
                // printf("%i %i tabulate func \n", candidates[0].votes, candidates[1].votes);
                break;   
            }
        }
    }    
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // printf("%i %i \n", candidates[i].votes , voter_count);
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("%i %i \n", candidates[i].votes , voter_count);
        float percent = (float) candidates[i].votes / voter_count;
        // printf("%f %i %i \n", percent, candidates[i].votes , voter_count);
        if (percent > 0.51)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min;

    // найти первого невыбывшего кандидата
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            min = candidates[i].votes;
            break;
        }
    }

    // найти минимальное значение
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    // printf("%i\n", min);
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
            candidates[i].eliminated = true;
    }
    return;
}

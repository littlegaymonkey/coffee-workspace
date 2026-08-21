def main():
    text = input("Text: ")
    letters = letter_count(text)
    word = word_count(text)
    senten = sentences_count(text)
    cl_index = round(index(letters, word, senten))
    if cl_index < 1:
        print("Before Grade 1")
    elif cl_index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {cl_index}")

def letter_count(text_input):
    sum_total = 0
    for i in text_input:
        if i.isalpha():
            sum_total += 1
    return sum_total


def word_count(text_input):
    sum_total = 1
    for i in text_input:
        if i in (" ", "\n"):
            sum_total += 1
    return sum_total


def sentences_count(text_input):
    sum_total = 0
    for i in text_input:
        if i in (".", "!", "?"):
            sum_total += 1
    return sum_total


def index(letter, words, sentenses):
    try:
        index1 = (
            0.0588 * ((letter / words) * 100)
            - 0.296 * ((sentenses / words) * 100)
            - 15.8
        )
        return index1
    except ZeroDivisionError:
        return 0



if __name__ == "__main__":
    main()

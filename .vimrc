" Номера строк как в VS Code
set number
set norelativenumber
highlight LineNr ctermfg=242 guifg=#888888

set mouse=a

" Подсветка синтаксиса C
 filetype plugin indent on
 au BufRead,BufNewFile *.c,*.h setlocal cindent

"Табы в пробелы
set tabstop=4
set shiftwidth=4
set expandtab

"Пробелы точками при режиме выделения
augroup ShowSpacesOnSelect
autocmd!
autocmd ModeChanged *:[vV\x16]* set list
autocmd ModeChanged [vV\x16]*:* set nolist
augroup END

set listchars=space:·,tab:»·

"Для одног цвета в тмукс и терминале
set background=light

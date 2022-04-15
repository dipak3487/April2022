" Turns on syntax highlighting
syntax on 

"this is for autopreview:
set nobackup
set updatetime=800	"less than a second
set ruler

"show short description of tags
set noshowfulltag

"show underline at cursor line
"set cursorline
"set cursorcolumn

set autoindent
set smartindent

set cst	"test - to observe tag sequence

set hlsearch
set incsearch

set nocompatible

set showmatch
set wildmenu
set wildchar=<Tab>

set textwidth=0

set title
set showcmd
set history=100
set undolevels=100

set novisualbell 
set noerrorbells 

set ttyfast

set tabstop=4
set softtabstop=4
set shiftwidth=4
set smarttab

set scrolljump=1 				" lines to scroll when cursor leaves screen
set scrolloff=2 				" minimum lines to keep above and below cursor


set backspace=indent,eol,start

set guifont=fixed,vt100:h12,Consolas:h10:b
"set guifont=fixed,vt100:h10,Lucida_Sans_Typewriter:h10:b
set guioptions-=T

"set TODO color different than search
hi Todo  ctermfg=red  ctermbg=gray guifg=red guibg=gray


map ,v :sp $HOME/.vimrc<CR><C-W>_ " edit my .vimrc file in a split
map ,V :source $HOME/.vimrc<CR><Left> " update the system settings from my vimrc file


map <F2> :w<CR>
imap <F2> <ESC>:w<CR>i<RIGHT>

map <F3> :q<CR>
imap <F3> <ESC>:q<CR>

map <F4> :%s/<C-R>=expand("<cword>")<CR>/<C-R>=expand("<cword>")<CR>/cg<Left><Left><Left>
imap <F4> <esc>:%s/<C-R>=expand("<cword>")<CR>/<C-R>=expand("<cword>")<CR>/cg<Left><Left><Left>

"comments start with double quote, till end of line
map <F5> :!make<CR>
imap <F5> <ESC>:!make<CR>i<RIGHT>


map <F8> :!ctags -Rf .tags<CR>
imap <F8> <ESC>:!ctags -Rf .tags<CR>i<RIGHT>

map <F9> :!./program<CR>
imap <F9> <ESC>:!./program<CR>i<RIGHT>

map <F10> :se nu!<CR>
imap <F10> <ESC>:se nu!<CR>i<RIGHT>


let &tags=".tags"

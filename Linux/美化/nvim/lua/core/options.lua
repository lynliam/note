local opt = vim.opt

--line number
opt.relativenumber = true
opt.number = true

--suojin
opt.tabstop = 2
opt.shiftwidth = 2
opt.expandtab = true
opt.autoindent = true

--fangzhibaoguo
opt.wrap = false

--guangbiao
--
opt.cursorline = true

--shubiao
opt.mouse:append("a")

--jianqieban
opt.clipboard:append("unnamedplus")

--xinchuangkou youxia
opt.splitright = true
opt.splitbelow = true
--
opt.ignorecase = true
opt.smartcase = true

--appearence 
opt.termguicolors = true
opt.signcolumn = "yes"
vim.cmd[[colorscheme tokyonight-moon]]


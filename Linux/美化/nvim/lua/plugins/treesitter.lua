require'nvim-treesitter.configs'.setup {
  -- A list of parser names, or "all" (the five listed parsers should always be installed)
ensure_installed = {"vim", "bash", "c", "cpp", "java", "javascript", "python", "lua" },  
  highlight = { enble = true },
  indent = { enable = true},

  rainbow = {
    enable = true,
    extended_mode = true,
    max_file_lines = nil,
  }
}

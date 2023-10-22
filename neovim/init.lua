
-- Install lazypath
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", -- latest stable release
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

-- Plugins
require("lazy").setup(
    {
        {
            "akinsho/bufferline.nvim",
            version = "*",
            dependencies = "nvim-tree/nvim-web-devicons",
        },
        {
            "folke/tokyonight.nvim",
        },
        {
            "navarasu/onedark.nvim",
        },
        {
            "nvim-lualine/lualine.nvim",
            dependencies = "nvim-tree/nvim-web-devicons",
        },
        {
           "vimpostor/vim-tpipeline",
        },
    }
)


-- Bufferline
local bufferline = require("bufferline")
bufferline.setup{
    options = {
        numbers = "buffer_id",
        style_preset = {
            bufferline.style_preset.no_italic,
            bufferline.style_preset.no_bold,
            bufferline.style_preset.minimal,
        },
        show_buffer_icons = false,
        show_buffer_close_icons = false,
    }
}

-- Tokyonight
require("tokyonight").setup {
    style = "night"
}
require("onedark").setup {
    style = "dark"
}
vim.cmd("colorscheme tokyonight-night")

-- Lualine
require("lualine").setup {
    options = {
        theme = "tokyonight"
    }
}
-- Vim tpipeline
vim.g.tpipeline_autoembed = 0

-- Global configs
vim.opt.number = true
vim.opt.mouse = 'a'
vim.o.tabstop = 4 -- A TAB character looks like 4 spaces
vim.o.expandtab = true -- Pressing the TAB key will insert spaces instead of a TAB character
vim.o.softtabstop = 4 -- Number of spaces inserted instead of a TAB character
vim.o.shiftwidth = 4 -- Number of spaces inserted when indenting
vim.opt.termguicolors = true

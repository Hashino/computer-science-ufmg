
local dap = require("dap")

dap.adapters.lldb = {
  type = "executable",
  command = "/usr/bin/lldb-dap", -- adjust as needed
  name = "lldb",
}

dap.configurations.c = {
  {
    name = "main",
    type = "lldb",
    request = "launch",
    program = function()
      os.execute("make")
      return vim.fn.getcwd() .. "/bin/" .. "order"
    end,
    cwd = "${workspaceFolder}",
    stopOnEntry = false,
    runInTerminal = true,
    args = { '-d', '-f', '/home/hashino/Documents/cs-ufmg/3-ED/TP1/cad/test.xcsv' },
  },
}

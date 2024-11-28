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
      return vim.fn.getcwd() .. "/bin/" .. "tp1.out"
    end,
    cwd = "${workspaceFolder}",
    stopOnEntry = false,
    runInTerminal = true,
    args = { '-d', '-a', 'Qc', '-o', 'd', '-f', './cad/test.xcsv' },
  },
}

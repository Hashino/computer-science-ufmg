--------------------------------------------------------------------------------

local bin_name = "pa3";
local debug_args = "-n 25 -a fib";

--------------------------------------------------------------------------------

local dap = require("dap")

local function split_args(inputstr, sep)
  if sep == nil then
    sep = "%s"
  end
  local t = {}
  for str in string.gmatch(inputstr, "([^" .. sep .. "]+)") do
    table.insert(t, str)
  end
  return t
end

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
      os.execute("make all")
      return vim.fn.getcwd() .. "/bin/" .. bin_name
    end,
    cwd = "${workspaceFolder}",
    stopOnEntry = false,
    runInTerminal = true,
    args = split_args(debug_args, ' ')
  },
}

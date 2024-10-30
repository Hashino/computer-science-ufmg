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

local debug_args = "-z 9 -s 28 -a q3";

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
      return vim.fn.getcwd() .. "/bin/" .. "pa1.out"
    end,
    cwd = "${workspaceFolder}",
    stopOnEntry = false,
    runInTerminal = true,
    args = split_args(debug_args, ' ')
  },
}

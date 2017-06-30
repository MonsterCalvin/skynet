local skynet = require("skynet")

skynet.start(function()

	skynet.error("Main Service Start ..."))
	kynet.newservice("debug_console",8000)

	skynet.exit()
end)
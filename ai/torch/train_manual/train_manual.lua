local log = require '../lumin_log'

require 'torch'
require 'nn'

-->
log.debug('setup network')
mlp = nn.Sequential()

mlp:add(nn.Linear(2,20))
mlp:add(nn.Tanh())
mlp:add(nn.Linear(20,1))

crit = nn.MSECriterion()

-->
log.warn('start training')
for i = 1, 8000 do
	if 0 == i % 100 then
		log.info('iteration '.. i)
	end
	local input = torch.randn(2)
	local output = torch.Tensor(1)
	if input[1]*input[2] > 0 then
		output[1] = -1
	else
		output[1] = 1
	end

	local netout = mlp:forward(input)
	crit:forward(netout, output)

	mlp:zeroGradParameters()
	local critback = crit:backward(mlp.output, output)
	mlp:backward(input, critback)

	mlp:updateParameters(0.01)
end

-->
log.warn('start eval')
for i = 1, 5 do
	log.info('iter' .. i)
	local x = torch.randn(2)
	print ('    input  (', x[1], ',', x[2], ')')
	local fx = mlp:forward(x)
	print ('    output (', fx[1], ')')
end

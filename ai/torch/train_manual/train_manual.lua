local log = require '../lumin_log'

require 'torch'
require 'nn'

-->
log.debug('setup network')
mlp = nn.Sequential()
mlp:add(nn.Linear(2,20))
mlp:add(nn.Tanh())
mlp:add(nn.Linear(20,1))
print (mlp)

log.debug('crit')
crit = nn.MSECriterion()
print (crit)

-->
log.warn('start training')
for i = 1, 8000 do
	if 0 == i % 500 then
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
	local loss = crit:forward(netout, output)
	if 0 == i % 500 then
		print ('  loss ', loss)
	end

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
	print ('    input  (', x[1], ',', x[2], ')', torch.type(x))
	local fx = mlp:forward(x)
	print ('    output (', fx[1], ')', torch.type(fx))
	local gt = 0.
	if x[1]*x[2] > 0 then
		gt = -1
	else
		gt = 1
	end
	local GT = torch.Tensor(1):fill(gt)
	local loss = crit:forward(fx, GT)
	print ('    loss   (', loss, ')')
end

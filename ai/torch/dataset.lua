require 'torch'
dataset = {};

function dataset:size()
	return 5000
end

function dataset:populate()
	for i = 1, dataset:size() do
		local input = torch.randn(2)
		local output = torch.Tensor(1)
		if input[1]*input[2] > 0 then
			output[1] = -1
		else
			output[1] = 1
		end
		dataset[i] = {input, output}
	end
end

return dataset

Torch reference
===
>Lumin Zhou

This is a brief note of torch7 documentations.

---  
## [nn.Module](https://github.com/torch/nn/blob/master/doc/module.md)  
#### methods
1. [output] forward(input)  
  It is not advised to override this function.
	Instead, one should implement updateOutput(input) function.  
2. [gradinput] backward(input, gradOutput)  
  It is not advised to override this function call in custom classes.
 	It is better to override updateGradInput(input, gradOutput)
 	and accGradParameters(input, gradOutput,scale) functions.  
3. updateOutput(input)  
4. updateGradInput(input, gradOutput)  
5. accGradParameters(input, gradOutput, scale)  
  Zeroing this accumulation is achieved with zeroGradParameters()
 	and updating the parameters according to this accumulation is
 	done with updateParameters().  
5. zeroGradParameters()  
6. updateParameters(learningRate)  
  parameters = parameters - learningRate * gradients_wrt_parameters  
7. accUpdateGradParameters(input, gradOutput, learningRate)  
8. share(mlp, s1, s2, ..., sn)  
  shares parameters with specified modules.  
9. clone(mlp, ...)  
  creates deep copy of specified modules.  
10. type(type[, tensorCache])  
  converts all the parameters of a module to the specified type (torch.Tensor).  
11. float()  
  shortcut to module:type('torch.FloatTensor')  
12. double()
  shortcut to module:type('torch.DoubleTensor')  
13. cuda()
  shortcut to module:type('torch.CudaTensor')  
14. training()  
  toggles training mode for a module  
15. evaluate()  
  toggles evaluation mode for a module  
16. findModules(typename)  
17. listModules()  
18. clearState()  
  clears intermediate modules states as output, gradInput and others.  
#### variables
1. output  
  results of forward(input) will be put here  
2. gradinput  
  results of updateGradInput(input, gradOutput) will be put here  
3. [{weights}, {gradWeights}] parameters()  
4. [flatParameters, flatGradParameters] getParameters()  
--- 


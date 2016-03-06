Torch reference
===
>Lumin Zhou

This is a brief note of torch7 documentations.

---
## [torch.Tensor](https://github.com/torch/torch7/blob/master/doc/tensor.md)  

#### constructors
1. torch.Tensor()  
  returns an empty tensor  
2. torch.Tensor(tensor)  
  returns a new tensor but refers the same storage than the origin  
3. torch.Tensor(size1[, size2[, size3[, size4]]])  
  creates a tensor up to 4 dimensions  
4. torch.Tensor(sizes, [strides])  
  creates a tensor of any number of dimensions  
5. torch.Tensor(storage, [storageOffset, sizes, [strides]])  
  returns a tensor which uses the existing storage.  
6. torch.Tensor(storage, [storageOffset, size1[, ...[, sz4[, st4]]]])  
7. torch.Tensor(table)  
  constructs a tensor from lua table  

#### clone
1. [Tensor] clone()  
	returns a clone of tensor. memory is copied.  
2. [Tensor] contiguouts()  
	returns an tensor contiguous in memory.  
3. [Tensor or string] type(type)  
	describes tensor type when type is nil, but when type is a string,
	return a new tensor in specified type.  
4. [Tensor] typeAs(tensor)  
	shortcut to `type(tensor:type())`  
5. [boolean] isTensor(object)  
6. [Tensor] byte(), char(), short(), int(), long(), float(), double()  
	shortcut to type(xxx)  

#### size and structure
1. [number] nDimension()  
	how many dimensions does a tensor have  
2. [number] dim()  
	alias to nDimensions()  
3. [number] size(dim)  
	size of specified dim.  
4. [LongStorage] size()  
5. [LongStorage] #self  
	same as size()  
6. [number] stride(dim)  
	returns jump size in memory  
7. [LongStorage] stride()  
	returns jump size in each dimension, in memory  
8. [Storage] storage()  
	returns storage used to store tensor elements, a way of dumping tensors.  
9. [boolean] isContiguous()  
	whether a tensor is contiguous in memory  
10. [boolean] isSize(storage)  
11. [boolean] isSameSizeAs(tensor)  
12. [number] nElement()  
13. [number] storageOffset()  

#### querying elements
1. x\[2\]\[3\]  
2. x[\{2,3\}]  

#### referencing tensor to existing tensor or memory chunk
1. [self] set(tensor)  
	The Tensor is now going to "view" the same storage as the given tensor  
2. [boolean] isSetTo(tensor)  
3. [self] set(storage, [storageOffset, sizes, [strides]])  
4. [self] set(storage, [storageOffset, sz1 [, st1 ... [, sz4 [, st4]]]])  

#### copying and initializing
1. [self] copy(tensor)  
	Replace the elements of the Tensor by copying the elements of the given tensor  
2. [self] fill(value)  
	fill the tensor with the given value  
3. [self] zeor()  
	fill the tensor with zeros  

#### resizing
1. [self] resizeAs(tensor)  
2. [self] resize(sizes)  
3. [self] resize(sz1 [,sz2 [,sz3 [,sz4]]]])  

#### Extracting sub-tensors (Slicing operations)
1. [self] narrow(dim, index, size)  
2. [Tensor] sub(dim1s, dim1e ... [, dim4s [, dim4e]])  
3. [Tensor] select(dim, index)  
4. \[Tensor\] [{ dim1,dim2,... }] or [{ {dim1s,dim1e}, {dim2s,dim2e} }]  
5. [Tensor] index(dim, index)  
6. [Tensor] indexCopy(dim, index, tensor)  
7. [Tensor] indexAdd(dim, index, tensor)  
8. [Tensor] indexfill(dim, index, val)  
9. [Tensor] gather(dim, index)  
10. [Tensor] scatter(dim, index, src|val)  
11. [Tensor] maskedSelect(mask)  
12. [Tensor] maskedCopy(mask, tensor)  
13. [Tensor] maskedFill(mask, val)  

#### searching
1. [LongTensor] nonzero(tensor)  

#### expanding/replicating/squeezing tensors
1. [result] expand([result,] sizes)  
2. [result] expandAs([result,] tensor)  
3. [Tensor] repeatTensor([result,] sizes)  
4. [Tensor] squeeze([dim])  

#### Manipulating the tensor view
1. [result] view([result,] tensor, sizes)  
2. [result] viewAs([result,] tensor, template)  
3. [Tensor] transpose(dim1, dim2)  
4. [Tensor] t()  
	shortcut transpose for 2D tensors  
5. [Tensor] permute(dim1, dim2, ..., dimn)  
6. [Tensor] unfold(dim, size, step)  

#### Applying a function to a tensor
1. [self] apply(function)  
2. [self] map(tensor, function(xs, xt))   
3. [self] map2(tensor1, tensor2, function(x, xt1, xt2))  

#### Dividing a tensor into a table of tensors
1. [result] split([result,] tensor, size, [dim])  
2. [result] chunk([result,] tensor, n, [dim])  

#### LuaJIT FFI access
1. [result] data(tensor, [asnumber])  
2. [result] cdata(tensor, [asnumber])  

#### Reference counting
1. retain()  
2. free()  

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


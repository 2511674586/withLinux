Big Talk Design Pattern
---
> 大话设计模式，程杰，清华出版社

## 简单工厂模式

业务封装，前后端分离，增加复用可能性
```c++
double GetResult (string operator, double operandA, double operandB);
```

紧耦合，松耦合
```
class Operation 
{
	private:
		double numberA_ = 0.;
		double numberB_ = 0.;
	public:
		double get_nA ();
		double set_nA ();
		double get_nB ();
		double set_nB ();
		virtual double GetResult ();
}
```
then create OperationAdd, inherits from Operation. After that
overload the `GetResult()` method.
```
class OperationAdd : Operation
{
	override double GetResult ();
}
```

简单工厂模式
```
class OperationFactory
{
	Operation createOperation(string op);
	// switch op: case(+) => return OperationAdd();
	// ...
}

Operation op;
op = OperationFactory.createOperation("+");
op.set_nA (xxx);
op.set_nB (xxx);
double result = op.GetResult();
```

UML图

## 策略模式



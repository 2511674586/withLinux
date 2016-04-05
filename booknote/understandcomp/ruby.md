Chap1. RUBY
---

using shell `irb`

# shell

```irb
irb(main):001:0> 1+2
=> 3
irb(main):002:0> x = 2
=> 2
irb(main):003:0> y = 3
=> 3
irb(main):004:0> x+y
=> 5
```

# value

boolean, number, string
```irb
irb(main):005:0> (true && false) || true
=> true
irb(main):006:0> (3+3)/(14*2)
=> 0
irb(main):007:0> (3+3)*(14*2)
=> 168
irb(main):008:0> (3+3)*(14/2)
=> 42
irb(main):009:0> 'hello' + ' world'
=> "hello world"
irb(main):010:0> 'hello'.slice(2)
=> "l"
irb(main):011:0> 'hello'.slice(1)
=> "e"
```

symbol and nil
```
irb(main):012:0> :my_symb
=> :my_symb
irb(main):014:0> :my_symb == :my_symb
=> true
irb(main):015:0> 'hello'.slice(99)
=> nil
```

data structures  

list
```irb
irb(main):001:0> nums = [ 'zero', 'one' ]
=> ["zero", "one"]
irb(main):002:0> nums[1]
=> "one"
irb(main):003:0> nums.push('two', 'three')
=> ["zero", "one", "two", "three"]
irb(main):004:0> nums
=> ["zero", "one", "two", "three"]
irb(main):005:0> nums.drop(1)
=> ["one", "two", "three"]
```

range
```
irb(main):006:0> ages = 18 .. 30
=> 18..30
irb(main):007:0> ages.entries
=> [18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
irb(main):008:0> ages.include?(25)
=> true
irb(main):009:0> ages.include?(255)
=> false
```

hash list, 'key' -> 'value'
```
irb(main):010:0> food = { 'a' => 'apple', 'b' => 'banana' }
=> {"a"=>"apple", "b"=>"banana"}
irb(main):011:0> food['b']
=> "banana"
irb(main):012:0> food['p'] = 'pear'
=> "pear"
irb(main):013:0> food
=> {"a"=>"apple", "b"=>"banana", "p"=>"pear"}
```

another syntax for hash list
```
irb(main):014:0> dims = { width: 100, height: 50 }
=> {:width=>100, :height=>50}
irb(main):015:0> dims[:width]
=> 100
```

proc (a part of ruby code that has not been evaluated, i.e. lambda function, anonymous function)
```
irb(main):016:0> mul = -> x, y { x * y }
=> #<Proc:0x000000018a34b8@(irb):16 (lambda)>
irb(main):017:0> mul.call(3,4)
=> 12
irb(main):018:0> mul[3,4]
=> 12
```

# control flow  

```
irb(main):001:0> if 2 < 3
irb(main):002:1> 'less'
irb(main):003:1> else
irb(main):004:1* 'more'
irb(main):005:1> end
=> "less"
irb(main):006:0> quantify = -> number {
irb(main):007:1* case number
irb(main):008:2> when 1
irb(main):009:2> 'one'
irb(main):010:2> when 2
irb(main):011:2> 'a couple'
irb(main):012:2> else
irb(main):013:2* 'many'
irb(main):014:2> end
irb(main):015:1> }
=> #<Proc:0x00000001fba6c0@(irb):6 (lambda)>
irb(main):016:0> quantify.call(2)
=> "a couple"
irb(main):017:0> quantify.call(500)
=> "many"

irb(main):019:0> while x < 1000
irb(main):020:1> x = x * 2
irb(main):021:1> end
=> nil
irb(main):022:0> x
=> 1024
```

# object and method

```
irb(main):001:0> o = Object.new
=> #<Object:0x00000001daa8d0>
irb(main):002:0> def o.add(x,y)
irb(main):003:1>  x+y
irb(main):004:1> end
=> :add
irb(main):005:0> o.add(1,9)
=> 10
irb(main):006:0> def o.addadd(x,y)
irb(main):007:1>  add(x,y)+add(x,y)
irb(main):008:1> end
=> :addadd
irb(main):009:0> o.addadd(9,1)
=> 20
irb(main):010:0> def mult(a, b)
irb(main):011:1>  a*b
irb(main):012:1> end
=> :mult
irb(main):013:0> mult(5, 5)
=> 25
```

# class and module
```
irb(main):001:0> class Calculator
irb(main):002:1>  def divide(x, y)
irb(main):003:2>   x/y
irb(main):004:2>  end
irb(main):005:1> end
=> :divide
irb(main):006:0> c = Calculator.new
=> #<Calculator:0x00000001e78500>
irb(main):007:0> c.class
=> Calculator
irb(main):008:0> c.divide(10, 2)
=> 5
irb(main):009:0> divide(10, 2)
NoMethodError: undefined method `divide' for main:Object
from (irb):9
from /usr/bin/irb:11:in `<main>'
irb(main):010:0> class MultiplyingCalculator < Calculator
irb(main):011:1>  def multiply(x, y)
irb(main):012:2>   x * y
irb(main):013:2>  end
irb(main):014:1> end
=> :multiply
irb(main):016:0> mc = MultiplyingCalculator.new
=> #<MultiplyingCalculator:0x00000001e94778>
irb(main):017:0> mc.class
=> MultiplyingCalculator
irb(main):018:0> mc.class.superclass
=> Calculator
irb(main):019:0> mc.multiply(10, 2)
=> 20
irb(main):020:0> mc.divide(10, 2)
=> 5
```

```
class BinaryMultiplyingCalculator < MultiplyingCalculator
 def multiply(x, y)
  result = super(x, y)
  result.to_s(2)
 end
end

bmc = BinaryMultiplyingCalculator.new

bmc.multiply(10, 2)
=> "10100"
```

```
module Addition
 def add(x, y)
  x+y
 end
end

class AddingCalculator
 inclue Addition
end

ac = AddingCalculator.new

ac.add(10, 2)
=> 12
```

# other

### local variable and value assigning
```
greeting = 'hello'

width, height, depth = [ 1000, 2000, 200 ]
```

### string insertion
```
"hello #{'dlrow'.reverse}"
=> "hello world"
```

```
o = Object.new
def o.to_s
 'a new object'
end

"here is #{o}"
=> "here is a new object"
```

### checking object
```
o = Object.new
def o.inspect
 '[my object]'
end

o
=> [my object]
```

### string printing
```
x = 128
while x < 1000
 puts "x is #{x}"
 x = x * 2
end
```

### variadic method
```
def join_with_commas(*words)
 word.join(', ')
end

join_with_commas('one', 'two')
=> "one, two"
```

```
def join_with_commas(before, *words, after)
 before + words.join(', ') + after
end

join_with_commas('testing: ', 'one', 'two', '.')
=> "testing: one, two."

arguments = ['testing: ', 'one', 'two', '.']
join_with_commas(*arguments)

before, *words, after = ['testing: ', 'one', 'two', '.']
```

### code block  
```
def do_three_times
 yield
 yield
 yield
end

do_three_times { puts 'hello' }
=> hello
=> hello
=> hello
```

TODO

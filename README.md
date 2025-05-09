<p>
<a href="https://www.storage-b.com/math-numerical-analysis/492">Polynomial</a> is a C++ class facilitating the evaluation of polynomials of a single indeterminate.
</p>
<p>
<a href="https://github.com/jachappell/Polynomial/blob/master/examples/example1.cpp">example1.cpp</a> evaluates f(x) =  2x<sup>3</sup> - 3x<sup>2</sup> + 4x + 1 for values of x between -10 and 10.<br /><br /> 
<a href="https://github.com/jachappell/Polynomial/blob/master/examples/example2.cpp">example2.cpp</a> evaluates f(x) =  x<sup>4</sup> + 2x<sup>3</sup> - 3x<sup>2</sup> + 4x + 1 and its derivative for values of x between -10 and 10. 
</p>
<p>
See <a href="https://github.com/jachappell/Polynomial/blob/master/tests/test.cpp">test.cpp</a> for more examples.
</p>
<p>
To build the examples:
</p>
<pre>
$ mkdir build
$ cd build
$ cmake ..
$ make
</pre>
<p>To run examples:<p>
<pre>
$ ./example1
$ ./example2
</pre>
<p>
To build the tests:
</p>
<pre>
$ mkdir build
$ cd build
$ cmake ..
$ make
</pre>
<p>To run the tests:</p>
<pre>
./test
</pre>

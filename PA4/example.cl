
(*  Example cool program testing as many aspects of the code generator
    as possible.
 *)

class Main {
  main():Int { 0 };
};

class A {
	a : Int <- 5;
	b : Bool;
	c : B <- new B;
	d : String <- "Hello";

	a() : Int {
		5
	};
};

class D inherits A {};
class E inherits A {};
class B {};
class C {};



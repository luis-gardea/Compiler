
(*  Example cool program testing as many aspects of the code generator
    as possible.
 *)

class Main {
	main():Object {
		(new IO).out_int(5+5)
	};

	m(a:Int):Int {a+5};

	k: Int <- 5+5;--if 5=6 then 5 else 6 fi;
};

(*m(x:Int):Int {
	x+7
};
*)




(*class Main {
  main():Object { 0 };
  m(j:Int, k:Int) : Object {
  	let x:Int <- 5 in
  		let y:Int<-8 in 
  			x+y
  };

  m2(y:Int):Object {
  	m(y,8)
  };
  k:Object <- {m(89, 7); let x:Int<-90 in x + 2;}; 
  	{
  		
  		let m: Int <- 6 in m1(9);
  	}
  };
  m1 (a:Int) : Int {
  	m + 5
  };
  m : Int <- 5;
  n : Int <- 2;
  
};
class M inherits Main {
	j : Int <- 5;
};


class A {
	a : Int <- 5 + 4;
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
*)



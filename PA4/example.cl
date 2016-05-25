
(*  Example cool program testing as many aspects of the code generator
    as possible.
 *)

class Main {
	main():Object {
    (*case true of
      a:Int => a;

  };
}*)
    
    let io : IO <- new IO, b: B <- new B, a : Int <- a + 5, c : Int <- 7, d : Int <- c + k in {
      --io.out_string(j);
      --j <- "\nnew string\n";
		  io@IO.out_int(b.m(7));
      --io@IO.out_string(j);
      --io.out_int(k);
      io.out_int(m(7));
      io.out_int(a);
      io.out_int(c);
      io.out_int(d);
    }
    --(new IO).out_int((new B).m())
	};


	m(a:Int):Int {k + a};

  j: String <- "my string\n";

	k: Int <- a;

  a:Int <- 8;
};

(*m(x:Int):Int {
	x+7
};
*)

class B {
  m(a:Int) : Int {
    a+7
  };
};




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




(*  Example cool program testing as many aspects of the code generator
    as possible.
 *)

class Main {
	main():Object {
    while true loop x <- x + 1 pool
  };
  io : IO <- new IO;
  x : Int <- 7;
  f : Bool;
  a : A;
};

class A {

};
    (*
	    case y of
	      a:Int => io.out_int(a * 5 / 0 - a);
	      c:Object => io.out_int(2);
	      b:Bool => io.out_int(3);
	      d:Main => io.out_int(4);
        --e:A => io.out_int(5);
	      --f:B => io.out_int(6);
	      --g:C => io.out_int(7);
	      h:D => io.out_int(8);
	    esac
	    --a = b

	    (*while d = io loop
	    	{
	    		io.out_string("equal\n");
	    	}
	    pool*)
	};
  y:Int <-2;
	io:IO <- new IO;
	--a : A <- new A;
	--b : B <- new B;
  --c : C <- new C;
  --d : D <- new D;
	x:Bool <- true;
};

class A {};
class B inherits A {};
class C inherits B {};
class D inherits C {};*)
    
    (*let io : IO <- new IO, b: B <- new B, a : Int <- a + 5, c : Int <- 7, d : Int <- c + k in {
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
};*)

(*m(x:Int):Int {
	x+7
};
*)

(*class B inherits Main {
  m(a:Int) : Int {
    a+7
  };
};*)






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




(*  Example cool program testing as many aspects of the code generator
    as possible.
 *)

class Main inherits IO {
	main():Object {
    let x : Int <- 5 in {
      case x of
        y : Int => x <- 6;
        z : Object => x <- 7;
      esac;
      out_int(x);
      while x < 40 loop {
        out_int(x <- x*2);
        out_string("\n");
      } pool;
      (let c : Cool <- (new Cool).init(1, 1) in
        if c.reflect_X().reflect_Y() = c.reflect_0()
        then out_string("=)\n")
        else out_string("=(\n")
        fi
      );
    }
  };
  x : String;
  y:Int <- 10;
};

class A inherits IO {
  print(a:Int) : Object {
    {
      out_int(a);
      out_string("method in A\n");
    }
  };

  a() : Object {
    {
      case b of
        a:Int => io.out_int(a * 5 / 0 - a);
        c:Object => io.out_int(2);
        b:Bool => io.out_int(3);
        d:Main => io.out_int(4);
      esac;

      while d = io loop
          {
            io.out_string("equal\n");
          }
      pool;
    }
  };
  y:Int <-2;
  io:IO <- new IO;
  a : Int <- 10;
  x:Bool <- true;
  b: String <- "Hello";
  d : IO <- new IO;
};

class Cool inherits IO {
    x : Int;
    y : Int;

    init(a : Int, b : Int) : Cool {
  {
      x = a;
      y = b;
      self;
  }
    };

    print() : Object {
  if y = 0
  then out_int(x)
  else out_int(x).out_string("+").out_int(y).out_string("I")
  fi
    };

    reflect_0() : Cool {
  {
      x = ~x;
      y = ~y;
      self;
  }
    };

    reflect_X() : Cool {
  {
      y = ~y;
      self;
  }
    };

    reflect_Y() : Cool {
  {
      x = ~x;
      self;
  }
    };
};

class B inherits A {
  print(a:Int) : Object{
    {
      out_int(a);
      out_string("Method in B\n");
    }
  };
};

class C inherits B {};
class D inherits J {
  m(a:Int, k:Int): Int {
    {
    let io : IO <- new IO in 
        let b: J <- new J, a : Int <- a + 5 in 
          let c : Int <- 7, d : Int <- c + k, j:String in {
            io.out_string(j);
            j <- "\nnew string\n";
		        io@IO.out_int(b.m(7, 6));
            io@IO.out_string(j);
            io.out_int(k);
            io.out_int(m(7, 5));
            io.out_int(a);
            io.out_int(c);
            io.out_int(d);
          };
    (new IO).out_int((new D).m(5, 4));
    5;
    }
	};
};

class J inherits M {
  m(j:Int, k:Int) : Int {
  	let x:Int <- 5 in
  		let y:Int<-8 in 
  			x+y
  };

  m2(y:Int):Object {
  	m(y,8)
  };

  k:Object <- {let x :Int <- m(89, 7) in  
                let x:Int <- 90 in x <- m(89, 7);}; 

  m1(a:Int) : Int {
    {
      m + 5;
      let m: Int <- 6 in m1(9);
    }
  	
  };
  m : Int <- 5;
  n : Int <- 2;
};

class M inherits B {
	j : Int <- 5;
};




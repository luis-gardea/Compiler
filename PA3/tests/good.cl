class C {
	a : Int;
	b : Bool;
	init(x : Int, y : Bool) : C {
           {
		a <- x;
		b <- y;
		self;
           }
	};
};

class B inherits C {

};

class D inherits B {

};

class E inherits B {

};

class X inherits C {

};

Class Main {
	main():C {
	  (new C).init(1,true)
	};
};



class Main inherits IO {
    main() : SELF_TYPE {
	{
	    out_string((new Object).type_name().substr(4,1)). 
	    out_string((isvoid self).type_name().substr(1,3));
	    out_string("\n");
	}
    };
};

class B inherits Main {

<<<<<<< HEAD
};
=======
};
>>>>>>> 04c715673b3619bd1f612b084900a1cec838312d

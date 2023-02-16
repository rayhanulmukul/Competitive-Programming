 int i;
   double a, b, m,fa,fm;

   //Initialize variables

   fa = fm = 0.0;
   m = 0.0;
   clrscr();

  cout << "\n\t Enter initial value:";
   cin >> a;
   cout << a << endl;
   cin >> b;
   cout << b << endl;
   cout << "\n\n\t\t SOLUTION BY BISECTION METHOD"<< endl;

   // Bisection Method



  i = 1;

   while(i < MAX)
   {
      m = (a + b)/2.0;
      fa = (a * a * a) - 4 * a - 9;
      fm = (m * m * m) - 4 * m - 9;

      //Check the smaller intercal

      if(fa < 0 && fm > 0) {
	 b = m;
	 }
      else {
       a = m;
       }
      i++;

      }

      //Print the Results

      cout << "\n\t Result";
      cout << "\n\t Root is" << " " << m << endl;

      getch();

   }


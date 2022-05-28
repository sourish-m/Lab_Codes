class prime {
    public static void main(String[] args) {
       
	 top:
        for( int i=2;i<=101;i++)
	{ 
		 for (int j=2;j<i/2;j++)
                	if (i%j==0)
			 {
                    		continue top;
               		 }
             	 System.out.print(i+" ");
        }


    }
}

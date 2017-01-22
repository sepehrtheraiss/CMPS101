
public class ListTest {
	public static void main(String[] args){
	String str[] = {"one","two","three","four","five"};
	int i;
	String temp;
	for(int j=1;j<str.length;j++)
	{
		temp = str[j];
		i = j-1;
		while(i>=0 && temp.compareTo(str[i]) < 0)
		{
			str[i+1] = str[i];
			i = i-1;
		}
		str[i+1]=temp;
	}// end for
//	for(int a =0;a<str.length;a++)
//	{
//		System.out.println(str[a]);
//	}
	}

}

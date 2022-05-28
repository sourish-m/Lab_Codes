import java.util.*;
class wordends
{
    static String wordEnds(String str, String word) 
    {
        int strLen = str.length();
        int wordLen = word.length();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < strLen; i++){
            int prev = i-1;
            if(str.charAt(i) == word.charAt(0)){
                int count = 0;
                while(i < strLen && count < wordLen){
                    if(str.charAt(i) != word.charAt(count)){
                        break;
                    }
                    i++;
                    count++;
                }
                i--;
                if(count == wordLen){
                    if(prev >= 0)
                        sb.append(String.valueOf(str.charAt(prev)));
                    if(i+1 < strLen)
                        sb.append(String.valueOf(str.charAt(i+1)));
                }
            }
        }
        return sb.toString();
    }
    public static void main (String [] args)
    {
        Scanner sc= new Scanner( System.in );
        System.out.println("Enter a String");
        String str = sc.next();
        System.out.println("Enter a word");
        String word = sc.next();
        System.out.println(wordEnds(str,word));
    }
}

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Stack;

/**
 * Created by Balraj on 02-Feb-18.
 * Given a file check for any unbalanced parentheses placement
 */
public class Parentheses
{
    private static int checkParentheses(FileReader fr)
    {
        /*
            This method checks only for () misplacement
         */
        String line;
        int lineNumber=0;
        Stack<Character> stack = new Stack<>();
        BufferedReader br = new BufferedReader(fr);
        try
        {
            while((line=br.readLine())!=null)
            {
                int i=0;
                lineNumber++;
                while(i<line.length())
                {
                    char c = line.charAt(i++);

                    if(c=='(')
                    {
                        stack.push(c);
                    }
                    else if((stack.isEmpty())&&(c==')'))
                    {
                        System.out.println("wrong placement at line "+lineNumber);
                    }
                    else if(c==')')
                    {
                        stack.pop();
                    }
                }
            }
        }
        catch (Exception e)
        {
            System.out.print(e);
        }
        return 1;
    }

    private static void checkBrackets(FileReader fr)
    {
        /*
            This method checks for any type of bracket problem in the file.
         */
        int lineNumber = 0;
        char top,c;
        String currentLine;
        Stack<Character> stack = new Stack<>();
        BufferedReader br = new BufferedReader(fr);
        try
        {
            while((currentLine=br.readLine())!=null)
            {
                int index=0;
                lineNumber++;
                while(index<currentLine.length())
                {
                    c = currentLine.charAt(index++);
                    if((c=='(')||(c=='{')||(c=='['))
                    {
                        stack.push(c);
                    }
                    else if(!stack.isEmpty()&&((c==')')||(c=='}')||(c==']')))
                    {
                        top = stack.peek();

                        if(((top=='(')&&(c==')'))||((top=='{')&&(c=='}'))||((top=='[')&&(c==']')))
                        {
                            stack.pop();
                        }
                        else
                        {
                            System.out.println("Problem at line : "+lineNumber);
                        }
                    }
                    else if((stack.isEmpty())&&(c==')')||(c=='}')||(c==']'))
                    {
                        System.out.println("Problem at line : "+lineNumber);
                    }
                }
            }
        }
        catch(Exception e)
        {
            System.out.println("Got it "+e);
        }
    }
    public static void main(String[] args)
    {
        try
        {
            FileReader fr = new FileReader("myfile");
            checkBrackets(fr);
        } catch(Exception e)
        {
            System.out.println("Cant open the file");
        }
    }
}

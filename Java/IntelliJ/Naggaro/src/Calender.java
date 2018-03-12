/**
 * Created by Balraj on 22-Feb-18.
 * Given a date in format date/month/year and a value delta, find the date after delta days.
 */
public class Calender
{
    private static int[] daysOfMonth={31,28,31,30,31,30,31,31,30,31,30,31};

    private static boolean isLeap(int year)
    {
        return (year%4==0)&&((year%100!=0)||(year%400==0));
    }

    private static void calculateDate(int date,int month,int year,int delta)
    {
        if(isLeap(year)) daysOfMonth[1]=29;

        int currentDate=daysOfMonth[month-1];
        int currentMonth=month-1;
        int currentYear=year;
        int targetDate=date+delta;

        if(currentDate>=targetDate)
        {
            currentDate=targetDate;
        }
        else
        {
            if(currentMonth==11)
            {
                currentYear++;
                currentMonth=-1;
            }
            for(int i=currentMonth+1;i<12;i++)
            {
                if(isLeap(currentYear))
                {
                    daysOfMonth[1]=29;
                }
                else
                {
                    daysOfMonth[1]=28;
                }

                currentMonth=i;
                currentDate+=daysOfMonth[i];

                if(currentDate>targetDate)
                {
                    currentDate-=daysOfMonth[i];
                    currentDate= targetDate-currentDate;
                    break;
                }

                if(i==11)
                {
                    currentYear++;
                    i=0;
                }
            }
        }

        System.out.print("new date will be : "+currentDate+"/"+currentMonth+"/"+currentYear);
    }

    private static void calculateNewDate(int date,int month,int year,int delta)
    {
        setDaysOfMonth(year);

        int currentDate=0;
        int currentMonth=month-1;
        int currentYear=year;
        int targetDate=date+delta;

        for(int i=currentMonth;i<12;i++)
        {
            currentDate=currentDate+daysOfMonth[i];
            currentMonth=i;
            if(currentDate>=targetDate)
            {
                currentDate=daysOfMonth[i]-(currentDate-targetDate);
                break;
            }
            if(i==11)
            {
                i=-1;
                currentYear++;
                setDaysOfMonth(currentYear);
            }
        }

        System.out.print("Date is : "+currentDate+"/"+(currentMonth+1)+"/"+currentYear);

    }

    private static void setDaysOfMonth(int year)
    {
        if(isLeap(year)) daysOfMonth[1]=29;
        else daysOfMonth[1]=28;
    }

    public static void main(String[] args)
    {
        calculateNewDate(30,3,2018,6650);
    }
}

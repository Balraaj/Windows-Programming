/**
 * Created by Balraj on 22-Feb-18.
 * given two dates count the number of days between them in constant time.
 */
public class CalenderDaysBetweenDates
{
    private static class Date
    {
        int day;
        int month;
        int year;
        Date(int day,int month,int year)
        {
            this.day=day;
            this.month=month;
            this.year=year;
        }

    }
    private static int[] monthDays = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};

    private static int countLeapYears(Date d)
    {
        // Check if the current year needs to be considered
        // for the count of leap years or not
        if (d.month <= 2)
            d.year--;

        // An year is a leap year if it is a multiple of 4,
        // multiple of 400 and not a multiple of 100.
        return d.year / 4 - d.year / 100 + d.year / 400;
    }

    // This function returns number of days between two given
    // dates

    private static long getDifference(Date dt1, Date dt2)
    {
        // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
        // initialize count using years and day

        long n1 = dt1.year*365 + dt1.day;

        // Add days for months in given date
        for (int i=0; i<dt1.month - 1; i++)
            n1 += monthDays[i];

        // Since every leap year is of 366 days,
        // Add a day for every leap year
        n1 += countLeapYears(dt1);

        // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

        long n2 = dt2.year*365 + dt2.day;
        for (int i=0; i<dt2.month - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(dt2);

        // return difference between two counts
        return (n2 - n1);
    }

    // Driver program
    public static void main(String[] args)
    {
        Date dt1 = new Date(1,2,2000);
        Date dt2 = new Date(1,2,2004);

        System.out.println("Difference between two dates is : "+getDifference(dt1,dt2));

    }
}

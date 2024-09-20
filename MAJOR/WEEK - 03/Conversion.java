
public class Conversion {

    public static int decimalConversion(int binary) {
        int i = 0;
        int decimal = 0;

        while (binary != 0) {
            int rem = binary % 10;
            decimal = (int) (decimal + rem * Math.pow(2, i));
            binary = binary / 10;
            i++;
        }

        return decimal;
    }

    public static String binaryConversion(int num) {
         String str = "";
         
        while( num != 0){
            int rem = num % 2;
            str = rem + str;
            num /= 2;
        }
        
        return str ;
    }
}

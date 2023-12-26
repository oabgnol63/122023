import customclass.*;
import java.util.Vector;
public class test {
    public static void main(String[] args) {
        ar1920 a = new ar1920();
        int arr[] = new int[]{0,2,1,5,4,3};
        Vector<Integer> nums = new Vector<Integer>();
        for(int i = 0; i < arr.length; i++) {
            nums.addElement(arr[i]);
        }
        Vector<Integer> k = a.buildArray(nums);
        for(int i = 0; i < k.size(); i++) {
            System.out.println(k.get(i));
        }
    }
}
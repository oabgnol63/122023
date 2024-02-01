package customclass;
import java.util.Vector;
public class ar1920 {
    public Vector<Integer> buildArray(Vector<Integer> nums) {
        Vector<Integer> k = new Vector<Integer>();
        for(int i = 0; i < nums.size(); i++) {
            k.addElement(nums.get(nums.get(i)));
        }
        return k;
    }
};

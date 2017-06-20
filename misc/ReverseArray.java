import java.util.Arrays;
import java.util.List;
import java.util.Collections;

public class ReverseArray {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6};

        System.out.println("Hello ReverseArray...");
        System.out.println("Before: " + Arrays.toString(array));
        reverseArray(array);
        System.out.println("After: " + Arrays.toString(array));

        System.out.println("Hello ReverseArray2...");
        Integer[] array2 = {1, 2, 3, 4, 5};
        System.out.println("Before: " + Arrays.toString(array2));
        array2 = reverseArray2(array2);
        System.out.println("After: " + Arrays.toString(array2));
    }

    // swap elements at low and high
    public static void reverseArray(int[] data) {
        for (int low = 0, high = data.length - 1; low < high; low ++, high --) {
            int tmp = data[low];
            data[low] = data[high];
            data[high] = tmp;
        }
    }

    // use Collections.reverse
    public static Integer[] reverseArray2(Integer[] data) {
        List<Integer> list = Arrays.asList(data);
        Collections.reverse(list);
        Integer[] array = new Integer[data.length];
        list.toArray(array);

        return array;
    }
}

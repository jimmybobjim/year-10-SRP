import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static List<Integer> bubbleSort(List<Integer> elems) {
        boolean swapped;
        int temp;

        for (int i = 0; i < elems.size(); i++) {
            swapped = false;

            for (int j = 0; j < elems.size()-1; j++) {
                if (elems.get(j) > elems.get(j+1)) {
                    swapped = true;
                    temp = elems.get(j);
                    elems.set(j, elems.get(j+1));
                    elems.set(j+1, temp);
                }
            }

            if (!swapped) break;
        }

        return elems;
    }



    public static void main(String[] args) throws IOException {
        boolean print = false;
        String file;
        if (args.length == 0) {
            file = "reversed.csv";
        } else {
            file = args[0];
        }

        Scanner data = null;

        List<Integer> elems = new ArrayList<>();

        try{
            data = new Scanner(new File("../.numbers/" + file));

            while (data.hasNextLine()) {
                elems.add(Integer.parseInt(data.nextLine()));
            }

        } finally {
            if (data != null) {
                data.close();
            }
        }

        long startTime = System.nanoTime();
        List<Integer> result = bubbleSort(elems);
        long endTime = System.nanoTime();

        if (print) System.out.println(result);
        System.out.println("\nexecution time (ns): " + (endTime - startTime));
    }
}
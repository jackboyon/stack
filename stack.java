package test;

import java.util.Arrays;
import java.util.Scanner;

public class test {
    static Scanner sc = new Scanner(System.in);
    public static int peek(int[] arr, int size){
        if(isEmpty(arr)){
            return 0;
        }
        int index = index(arr, 0);
        return index;
    }
    public static boolean isFull(int size, int[] arr){
        int sizes = 0;
        for(int i = 0; i < size; i++){
            if(arr[i] != 0){
                sizes++;
            }
        }
        if(sizes == size){
            System.out.println("is full");
            return true;
        }
        System.out.println("is not full");
        return false;
    }

    public static boolean isEmpty(int[] arr){
        for(int i = 0; i < arr.length; i++){
            if(arr[i] !=0){
                System.out.println("is not empty");
                return false;
            }
        }
        System.out.println("is empty");
            return true;
    }

    public static int index(int[]arr, int size){
        int index = 0;
        for(int i = 0; i < size; i++){
            if(arr[i] != 0){
                index++;
            }
        }
        return index;
    }

    public static int[] pop(int[]arr, int size){
        if(isEmpty(arr)){
            return arr;
        }
        arr[index(arr, size) -1] = 0;
        return arr;
    }


    public static int[] push(int[]arr, int size){
            if(isFull(size, arr)){
            return arr;
        }
            try {
                System.out.println("enter a number: ");
                int numb = sc.nextInt();
                arr[index(arr, size)] = numb;
            } catch (Exception e) {
                System.out.println("invalid");
            }
        return arr;
    }

    public static void main(String[]args){
        int size = 5;
        int[] arr = new int[size];
        boolean run = true;
        while(run){
            System.out.println(Arrays.toString(arr));
                while(true){
                    System.out.print("""
                    #######################
                    1|peek
                    2|isEmpty
                    3|isFull
                    4|pop
                    5|push
                    #######################
                    """);
                    System.out.print("enter choice: ");
                    char ch = sc.next().charAt(0);
                    if(Character.isDigit(ch)){
                        int numb = Character.getNumericValue(ch);
                    switch(numb){
                        case 1: 
                        System.out.println("#######################");
                        System.out.println("top is "+peek(arr,size));
                            break;
                        case 2: 
                            System.out.println("#######################");
                            isEmpty(arr);
                            break;
                        case 3: 
                            System.out.println("#######################");
                            isFull(size, arr);
                            
                            break;
                        case 4: System.out.println("#######################");
                            arr=pop(arr, size);
                            break;
                        case 5: System.out.println("#######################");
                            arr = push(arr, size);
                            break;
                        default:
                            System.out.println("invalid");
                            continue;
                    }
                    break;
                    }else{
                        System.out.println("invalid");
                        sc.nextLine();
                    }
            }
            while(true){
                System.out.print(" Exit Y|N:");
                char exit = Character.toLowerCase(sc.next().charAt(0));

                if (Character.isDigit(exit)) {
                    System.out.println("Invalid input. Numbers not allowed.");
                    continue;
                }
                if (exit == 'y') {
                    System.out.println("Exiting...");
                    run = false;
                    break;
                } 
                if (exit == 'n') {
                    System.out.println("Continuing...");
                    break;
                }
                System.out.println("Invalid input. Please type Y or N.");
            }
    }
        sc.close();
    }
}

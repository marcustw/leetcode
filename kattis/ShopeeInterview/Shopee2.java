//import java.util.HashMap;
//import java.util.List;
//import java.util.ArrayList;
//import java.util.Arrays;
//class Main {
//// convertColor
//// convert hex format into rba value in term of array
//// convertColor('#000000') => [0, 0, 0]
//// convertColor('#FFA500') => [255, 165, 0]
//
//// 0-9 A: 10, B: 11, C: 12, D: 13, E: 14, F: 15
//// FF = 16 * 15 + 15 * 1
//// A = 16 * 10 + 10
//    static int[] convertColor(String hex) {
//
//        // Assume hex is always 7 characters long
//        // Time = O(1)
//        // Space = O(1)
//        int[] result = new int[3];
//        String hex2 = hex.substring(1);
//        for (int i = 0; i < 3; i++) {
//            result[i] = Integer.parseInt(hex2.substring(2*i, 2*i+2), 16); //Conversion O(1)
//        }
//        return result;
//    }
//
//
//// convertColorEx
//// convert hex format into rba value in term of array
//// convertColor('#000') => [0, 0, 0]
//// convertColor('#FFA') => [255, 255, 170]
//// #FFA => #FFFFAA
//    static int[] convertColorEx(String hex) { //O( substring ) = XX1XXXX
//                                                               //XX1
//                                                               // O(numOfCharacters)
//                                                               // subString(n, m) // O(m-n) // O(L)
//                                                               // string L
//                                                               // O(L)
//        // O(L) = O(1)
//        if (hex.length() == 7) {
//            return convertColor(hex);
//        }
//        // O(1)
//        String res = "#"; //StringBuilder StringBuffer
//        String hex2 = hex.substring(1);
//        for (int i = 0; i < 3; i++) {
//            res += hex2.substring(i, i+1);
//            res += hex2.substring(i, i+1);
//        }
//        System.out.println(res);
//        return convertColor(res);
//    }
//
//
//
//    static class Pair {
//        int id;
//        int qty;
//
//        Pair(int id, int qty) {
//            this.id = id;
//            this.qty = qty;
//        }
//    }
//
//    static class Cart {
//        List<Pair> cart;
//        Cart(List<Pair> cart){ this.cart = cart; }
//
//        @Override
//        public String toString() {
//            StringBuilder sb = new StringBuilder();
//            sb.append("[\n");
//            for (int i = 0; i < cart.size(); i++) {
//                Pair item = cart.get(i);
//                sb.append(String.format("{ id:%d, qty:%d }", item.id, item.qty));
//                if (i != cart.size() - 1) {
//                    sb.append(",");
//                }
//                sb.append("\n");
//            }
//            sb.append("]");
//            return sb.toString();
//        }
//    }
//
//    // HashMap<Integer, Integer> cart
//    // cart.contains(id) => cart.replace(id, newqty)
//    // cart.put(id, qty)
//
//    static Cart summarizeItems(Cart initialItems, Pair item) {
//        // Time: O(1)
//        boolean check = false;
//        int i = 0;
//        // O(n)
//        for (Pair it : initialItems.cart) {
//            if (it.id == item.id) {
//                check = true;
//                break;
//            }
//            i++;
//        }
//        if (check) {
//            Pair inside = initialItems.cart.get(i);
//            initialItems.cart.set(i, new Pair(item.id, inside.qty + item.qty));
//            //O(1)
//
//        } else {
//            //Time O(n)
//            //Space O(1)
//            initialItems.cart.add(item);
//        }
//        return initialItems;
//    }
//
//    public static void main(String[] args) {
//        System.out.println("Hello, world!");
//
//        /**
//        int[] arr = convertColor("#FFA500");
//        for (int j : arr) {
//            System.out.println(j);
//        }*/
//
//        int[] arr2 = convertColorEx("#FFA500");
//        for (int j : arr2) {
//            System.out.println(j);
//        }
//
//        Pair one = new Pair(1, 1);
//        Pair two = new Pair(2,2);
//        Pair three = new Pair(3,3);
//        List<Pair> cart = new ArrayList<>();
//        cart.add(one);
//        cart.add(two);
//        cart.add(three);
//        Cart initialItems = new Cart(cart);
//
//        System.out.println(summarizeItems(initialItems, new Pair(1,4)));
//    }
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

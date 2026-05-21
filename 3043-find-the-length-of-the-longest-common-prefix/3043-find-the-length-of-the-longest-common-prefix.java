class TrieNode {
    TrieNode[] children = new TrieNode[10];
}

class Trie {
    TrieNode root = new TrieNode();
    void insert(int num) {
        TrieNode node = root;
        String numStr = Integer.toString(num);
        for (char digit : numStr.toCharArray()) {
            int idx = digit - '0';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
    }

    int findLongestPrefix(int num) {
        TrieNode node = root;
        String numStr = Integer.toString(num);
        int len = 0;

        for (char digit : numStr.toCharArray()) {
            int idx = digit - '0';
            if (node.children[idx] != null) {
                len++;
                node = node.children[idx];
            } else {
                break;
            }
        }
        return len;
    }
}

class Solution {

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Trie trie = new Trie();

        for (int num : arr1) {
            trie.insert(num);
        }

        int longestPrefix = 0;

        for (int num : arr2) {
            int len = trie.findLongestPrefix(num);
            longestPrefix = Math.max(longestPrefix, len);
        }

        return longestPrefix;
    }
}
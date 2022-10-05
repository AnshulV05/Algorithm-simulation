package Dijkstra's_algorithm;

import java.util.Map.Entry;
import java.util.*;
import java.util.regex.*;
// import java.util.PriorityQueue;

// 
public class Graph implements Comparator<Node> {

    // Assume maximum path length to be less than INF
    private static Integer INF = 1000 * 1000 * 1000;

    // The map to store the nodes according to their names.
    private Map<String, Node> nodeMap = new HashMap<String, Node>();

    //Maps the nodes to their resp dist from source
    public Map<Node, Integer> d = new HashMap<Node, Integer>();

    // Simply adding a node to the list.
    public void addNode(String name) {
        /*
         * TODO: Implement this method
         */
        Node n = new Node(name);
        this.nodeMap.put(name, n);
    }

    public void addDirectedEdge(String nameA, String nameB, Integer distance) {
        /*
         * TODO: Implement this method
         * Check if nodes with nameA and nameB exist.
         */
        if (nodeMap.get(nameA) == null || nodeMap.get(nameB) == null) {
            return;
        } else {
            nodeMap.get(nameA).addNeighbour(nodeMap.get(nameB), distance);
        }
    }

    public Map<String, Integer> dijkstraAlgorithm(String source) {
        /*
         * TODO: Implement this method
         * Return a map of name of all the nodes
         * with the minimum distance from source node
         */

         //The priority Queue
        PriorityQueue<Node> Q = new PriorityQueue<Node>(100, this);

        //The map to be returned.
        Map<String, Integer> to_return = new HashMap<String, Integer>();

        //The d array which will store the min length of each node.
       
        for (String name : nodeMap.keySet()) {
            d.put(nodeMap.get(name), INF);
            Q.add(nodeMap.get(source));
        }
        d.put(nodeMap.get(source), 0);

        while(Q.size() != 0){
            Node u = Q.poll();
            for(Node v: u.adjacentNodes.keySet()){
                int alt = d.get(u) + u.adjacentNodes.get(v);
                if(alt < d.get(v)){
                    Q.remove(v);
                    d.put(v,alt);
                    Q.add(v);
                }
            }
        }
        //Finally d contains the required lengths

        //Filling the to_return
        for (String name : nodeMap.keySet()){
            to_return.put(name,d.get(nodeMap.get(name)));
        }
        return to_return;
    }
    public int compare(Node a1, Node a2) {
        if (d.get(a1) > d.get(a2))
            return 1;
        else if (d.get(a1) < d.get(a2))
            return -1;
        return 0;
    }
}

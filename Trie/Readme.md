# Orangutan Stories and Mango Feedings

## Objective
This project aims to provide practice with Tries in C while addressing a fictional problem related to tracking the names and mango feedings of orangutans in a park.

## Story
In our park, orangutans have unique backstories and names, but their names can change over time due to their adventures. To distinguish them, each orangutan gets a name. We like to feed them mangos as a treat, but we're concerned about overfeeding some and underfeeding others.
To address this, we track orangutan names and the mangos they've eaten. However, due to naming conventions changing, it's challenging to keep track of their stories.

## Problem
Given a list of name changes and feedings, we need to determine the number of mangos eaten by orangutans with a specific name prefix.

## Input
The input consists of:
- Two integers, `n` and `e`, representing the number of orangutans and events.
- `e` lines, each describing an event. An event can be:
  - `1 n a`: A feeding event, where `n` is the orangutan's name at the time of feeding, and `a` is the number of mangos given (1 ≤ a ≤ 100).
  - `2 o n`: A name change event, where `o` is the old name of the orangutan, and `n` is the new name.
  - `3 p`: An inquiry about the number of mangos eaten by orangutans whose names start with the character sequence `p`.

Each name and character sequence can have at most 20 characters. All names consist of uppercase Latin characters ('A' through 'Z'), and they do not contain whitespace. No orangutan changes its name to an existing name.

Assume that no orangutan has eaten before the given events.

## Output
For each inquiry event (`3 p`), print the number of mangos eaten by orangutans whose names start with the given character sequence `p`.

## Sample Input
10 6
1 BOB 5
1 BETTY 3
3 B
3 ALICE
2 BETTY ALICE
3 B
4 8
1 WILLIAM 4
1 WILL 6
3 WILLI
1 WILLIAN 9
1 WILLY 10
2 WILL MATT
1 WILLIAN 2
3 WILL

## Sample Output
8
0
5
25

## Explanation

### Case 1

There are 10 orangutans, but we only ever hear about 2 of them (initially BOB and BETTY).

**First Event:**
- BOB gets fed 5 mangos.

**Second Event:**
- BETTY gets fed 3 mangos.

**Third Event:**
- We want to know how many mangos have been given to orangutans whose names start with "B." Both BOB, who received 5 mangos, and BETTY, who received 3 mangos, have names that start with the letter "B." Thus, the total mangos given is 8.

**Fourth Event:**
- We want to know how many mangos have been given to orangutans whose names start with "ALICE." We do not know of any orangutans with names that start with "ALICE" that have been given a mango. Therefore, the answer is 0.

## Fifth Event

- **Description:** BETTY is changing their name to ALICE. This means that "BETTY" has eaten 0 mangos, and ALICE has eaten 3.
- **Explanation:** The orangutan named "BETTY" has changed its name to "ALICE." As "BETTY" did not eat any mangos, the mangos attributed to "BETTY" are 0. Meanwhile, "ALICE" has eaten 3 mangos.

## Sixth Event

- **Description:** We want to know how many mangos have been given to orangutans whose name starts with "B." BOB, who received 5 mangos, has a name that starts with the letter B, but since BETTY is no longer BETTY, we don't count them. Because of this, the total mangos given is 5.
- **Explanation:** The inquiry is about orangutans whose names start with the letter "B." Although BOB has received 5 mangos and initially "BETTY" was counted as well, after the name change in the previous event, "BETTY" is now "ALICE," so we only consider BOB. Therefore, the total mangos given to orangutans whose names start with "B" is 5.

---

## Case 2

- **Description:** There are 4 orangutans and 8 events.
- **Explanation:** In this case, there are 4 orangutans and 8 events, with various feedings and name changes.

### First Event

- **Description:** WILLIAM gets 4 mangos.
- **Explanation:** The orangutan named "WILLIAM" receives 4 mangos.

### Second Event

- **Description:** WILL gets 6 mangos.
- **Explanation:** The orangutan named "WILL" receives 6 mangos. At this point, the names and mangos for the orangutans are as follows:

```
Name           WILLIAM   WILL     ???      ???
Mangos         4         6       0        0
```

### Third Event

- **Description:** We want to know how many mangos orangutans whose names start with "WILLI" got. In this case, only WILLIAM meets the criteria. They got 4 mangos.
- **Explanation:** The inquiry is about orangutans whose names start with "WILLI." Among the orangutans, only "WILLIAM" matches this criteria, and they have received 4 mangos.

### Fourth Event

- **Description:** We feed WILLIAN 9 mangos.
- **Explanation:** The orangutan named "WILLIAN" receives 9 mangos. The names and mangos for the orangutans are updated as follows:

```
Name           WILLIAM   WILL     WILLIAN   ???
Mangos         4         6       9         0
```

### Fifth Event

- **Description:** We feed WILLY 10 mangos.
- **Explanation:** The orangutan named "WILLY" receives 10 mangos. The names and mangos for the orangutans are updated as follows:

```
Name           WILLIAM   WILL     WILLIAN   WILLY
Mangos         4         6       9         10
```

## Sixth Event

- **Description:** WILL changes their name to MATT.
- **Explanation:** The orangutan named "WILL" changes its name to "MATT." The names and mangos for the orangutans are updated as follows:

```
Name           WILLIAM   MATT    WILLIAN   WILLY
Mangos         4         6       11        10
```

## Seventh Event

- **Description:** WILLIAN gets 2 more mangos.
- **Explanation:** The orangutan named "WILLIAN" receives 2 more mangos. The names and mangos for the orangutans remain the same:

```
Name           WILLIAM   MATT    WILLIAN   WILLY
Mangos         4         6       11        10
```

## Eighth Event

- **Description:** We want to know how many mangos have been eaten by orangutans whose name starts with "WILL." The valid orangutans are WILLIAM, WILLIAN, and WILLY. The total mangos eaten is 4 + 11 + 10 = 25.

---

# Hints

## Graph: Use a Trie

To solve this problem efficiently, you can use a Trie data structure. The Trie should index based on the name of the orangutan. Each node in the Trie should represent a character in the orangutan's name.

## Recommended Function: Trie Functionality

The functionality of the Trie will be helpful if you implement the following operations:

1. Compute the sum for a subtree.
2. Increment a node's value, if it exists, or create a node if it does not.

## Node Data: Store Subtree Sum

It's recommended to store in each Trie node the sum of all descendants in the subtree rooted at that node. Storing this value makes computing the output for event type 3 (inquiries) fast. When you update a node, you also need to update all ancestor nodes if you store the subtree sum.

## Struct Definition Recommendation

You can define a struct for Trie nodes like this:

```cpp
struct TrieNode {
    TrieNode* children[26]; // Assuming uppercase Latin characters ('A' through 'Z')
    int subtreeSum;
    int nodeTotal;
};
```

- `children`: An array to store child nodes for each character in the alphabet.
- `subtreeSum`: The sum of all descendant nodes' values in the subtree rooted at this node.
- `nodeTotal`: The total value associated with this specific node.

## Name Change

When an orangutan changes its name, make sure to remove its sum from the old subtree. You can do this by subtracting its original value (mangos eaten) from the old name's Trie node and adding the same value to the new name's Trie node.

By following these hints and organizing your data structure and operations effectively, you should be able to efficiently solve the problem.

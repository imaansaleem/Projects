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

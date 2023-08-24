## Regression Using Gradient Descent
Gradient descent is an optimization algorithm used to minimize or maximize a function's value iteratively. The main idea behind gradient descent is to update the parameters of a model depending on the cost function. Here, The objective was to minimize function. So, We continue to update until we reach the minimum value after which no change was occurring in our parameters. It allows us to find the best-fit parameters for a given model and dataset, enabling effective learning and predictive performance.

## Algorithm
The steps of the Gradient Descent Algorithm involve:
1. Initialize Parameters
2. Compute the Cost Function
3. Compute the Gradient
4. Update the Parameters
5. Repeat Steps 2-4 till convergence (continue iterating until you get a stopping criterion)

## Explanation
Here are the answers to some that are responded using this approach

## Question 1 : 
What was learning rate of our gradient descent algo and what will happen if make it too small and too large?

## Answer:
The step size at which the parameters are modified after each iteration in the gradient descent technique is determined by the 
learning rate. Setting the learning rate too large or too small can have a variety of implications on the algorithm's performance.

### Small Learning Rate:
If the learning rate is too small, the algorithm will take small steps in parameter space during each iteration.
Advantages: It may result in more accurate parameter updates
Disadvantages: Given that it requires more iterations to attain the minimum, it will have a higher time complexity.
    
### Large Learning Rate: 
If the learning rate is too high, the algorithm will iteratively move in huge increments in the parameter space.

### Advantages: 
It will be less complicated in terms of time.

### Disadvantages: 
It may skip the desired value that we are finding as we are taking the large steps.

## Question 2 : 
What you understand from the learning curve what will be the effect of Alpha on our curve?   

## Answer:
For Small value of alpha, the algorithm makes tiny adjustments to its parameters each time it learns from the data. As a result, the learning curve shows that the algorithm improves slowly over time. So, curve will gradually move downwards
For Small value of alpha, the algorithm makes big adjustments to its parameters each time it learns from the data. As a result, the learning curve initially improves rapidly, and the error decreases quickly. However, if the learning rate is too large, the algorithm can go too far and miss the best solution. This can cause the error to increase or bounce around instead of steadily decreasing. The learning curve may look unstable or wavy, showing that the algorithm is having a hard time settling on the right solution.

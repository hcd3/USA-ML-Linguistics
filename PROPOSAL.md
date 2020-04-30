# Linguistic Differentiation ML Model

Author: Hrishikesh Deshmukh

---

### Overview

I want to create a **C++** application that interacts with the user and attempts to determine what region of 
the country they are from based on what they call certain every-day items.  The interface will allow the user 
to answer a series of questions about their linguistic tendencies.  For example, whether they use the term pop,
soda, or coke.  The machine learning model will train on data that represents these linguistic differences 
within the United States and attempt to accurately predict the user's region based on this data, outputting it 
to the screen.  This application will also include testing to determine the extent of the machine learning 
model's accuracy and the program's overall functionality.

### Motivation

I've always been somewhat intrigued by linguistic patterns and differences in speech around the world, and 
especially in the United States.  It's fascinating to think about how these starkly contrasting regional 
dialects arise and the factors at play behind these differences.  My attention was completely captured after 
meeting an individual from Wisconsin who referred to what I call a water fountain, as a *bubbler*.  I explored
the topic and found [this map.](https://www.businessinsider.com/22-maps-that-show-the-deepest-linguistic-conflicts-in-america-2013-6#maps-are-great-23) 
A Ph.D. student of statistics at North Caroline State University named *Joshua Katz* created this demonstrative 
visualization that showcases what I plan to base my machine learning model around.  My previous experience 
with this type of project includes utilizing the Naive Bayes library, which hopefully alleviates the burden of 
creating this program.

### Implementation

I plan on using the [Dlib library](https://github.com/davisking/dlib) for the machine learning model.  This
library is compatible with CMAKE as well as the Linux operating system.  If I were to finish the project early
or continue to work on it individually past the due date, I would utilize the [MyGUI library](https://github.com/MyGUI/mygui)
as a stretch goal to improve the user interaction with the application and make the program more visually
appealing to use.  By the end of week 1 my goal is to have set up and understood the **Dlib library** as well as
created and/or planned out the skeleton structure for the project.  Near the end of week 2 my goal is to have
generated the training data and begun to implement the machine learning algorithms.  At the end of the 3 week
deadline my goal is to have completed the machine learning algorithms, accuracy testing, and final touches.
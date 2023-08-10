rm(list=ls())
setwd("C:\\Users\\65181\\Desktop\\513")
df = read.csv('CS513_targeting_num.csv',header=TRUE, sep=",")

#Remove the rows with missing values 
df <- na.omit(df)

#Convert labels to factor class
df$Class<- factor(df$Class , levels = c("2","4") , labels = c("Benign","Malignant"))

#KNN

#Generate train and test in the ratio 70% to 30%
size <- sample(1:nrow(df), 0.7 * nrow(df)) 
nor <-function(x) { (x -min(x))/(max(x)-min(x))   }



df2 = df['Class']
#train set
train <- norm[size,] 
cl_train <- df2[size,]
##test set
test <- norm[-size,] 
cl_test <- df2[-size,]

#load the package class
library(class)

#run knn function for k = 3
clf <- knn(train,test,cl=cl_train,k=3)

#create confusion matrix
conf_matrix <- table(clf, cl_test)
print(conf_matrix)

#Accuracy
accuracy <- function(x){sum(diag(x)/(sum(rowSums(x)))) * 100}
accuracy(conf_matrix)


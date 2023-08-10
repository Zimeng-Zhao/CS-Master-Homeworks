# Course      : CS 513B
# Name        : Zimeng Zhao
# CWID        : 20012231



#Hierarchical
rm(list=ls()) 

#Load the data
filename<-file.choose()
data<-read.csv(filename, na.strings=c("?"), header=TRUE, sep=",")
data <- na.omit(data)

##Turn the Class column into factor value
data$Abs_cat<- factor(data$Abs_cat,labels = c("Abs_Med","Abs_low","Abs_High"))
head(data)
summary(data)
set.seed(123)
table(data$Abs_cat)

# Remove the Abs_cat variable，
# Perform hierarchical clustering
a_dist<-dist(data[,-4])
hclust_results<-hclust(a_dist)
plot(hclust_results)
hclust_2<-cutree(hclust_results,3)
table(hclust_2,data$Abs_cat)
?hclust


#kMeans
rm(list=ls()) 

#Load the data
filename<-file.choose()
data<-read.csv(filename, na.strings=c("?"), header=TRUE, sep=",")
data <- na.omit(data)

##Turn the Class column into factor value
data$Abs_cat<- factor(data$Abs_cat,labels = c("Abs_Med","Abs_low","Abs_High"))
head(data)
summary(data)
set.seed(123)

# Perform k-means clustering
kmeans_2<- kmeans(data[,-4],3,nstart = 10)
kmeans_2$cluster
table(kmeans_2$cluster,data$Abs_cat)
?kmeans# Add the centroids to the plot
centroids <- data.frame(cluster = factor(1:3), kmeans_2$centers)

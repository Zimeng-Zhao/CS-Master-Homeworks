#  Company    : Stevens 
#  Project    : CS513
#  Purpose    : hw2 
#  First Name : Zimeng
#  Last Name  : Zhao
#  Id			    : 20012231
#  Date       : 02/19/2023

#problem 1
rm(list=ls())

getwd()

setwd("C:\\Users\\65181\\Desktop\\513")
                                
getwd()


mydataset <- read.csv('breast-cancer-wisconsin.csv',na.string="?")

View(mydataset)

#I.	Summarizing each column (e.g. min, max, mean )
summary(mydataset)

#II.	Identifying missing values
md <- data.frame(mydataset)

View(md)

summary(md)

sum(is.na(md))

colSums(is.na(md))

#III.	Replacing the missing values with the “mean” of the column.
f6_mean <- mean(md$F6,method = "mean",na.rm = TRUE)

f6_mean

md$F6[is.na(md$F6)] <- f6_mean

View(md)

#IV.	Displaying the frequency table of “Class” vs. F6
ftable(md$Class,md$F6)

#V.	Displaying the scatter plot of F1 to F6, one pair at a time
pairs(md[2:7],main = "The Scatter Plot Of Breast Cancer",
      pch = 21,bg =c("yellow","blue")[factor(md$Class)])

#VI.	Show histogram box plot for columns F7 to F9
boxplot(md[8:10])

#problem2
rm(list=ls())

set2 <- read.csv('breast-cancer-wisconsin.csv',na.string="?")

View(set2)

set2_rm <- na.omit(set2)

View(set2_rm)
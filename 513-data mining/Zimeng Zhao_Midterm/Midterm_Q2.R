#Name :       Zimeng Zhao
#Student ID:  20012231
#Course:      CS513B

# clearing object environment
rm(list=ls())

# get working directory
getwd()

# set working directory
setwd("C:\\Users\\65181\\Desktop\\513")

# load data file
mydata <- read.csv('CS513_targeting_num.csv',na.string="?")

# load the package dplyr
library("dplyr")

# get numeric columns using dplyr() function            
print(select_if(mydata, is.numeric))

# I.summarizing each numerical column (e.g. min, max, mean )
summary(select_if(mydata, is.numeric))

#II.	Identifying missing values
md <- data.frame(mydata)

View(md)

sum(is.na(md))

colSums(is.na(md))

#III. Replacing the numerical missing values with the “median” of the corresponding columns
Income_median <- median(md$Income,method = "median",na.rm = TRUE)

Income_median

md$Income[is.na(md$Income)] <- Income_median

View(md)

#IV. Displaying the scatter plot of “Age”, and “Income”
pairs(~Age +Income,data = md, main = "The Scatter Plot Of Age and Income",
       pch = 21,bg=c("yellow","blue")[factor(md$Class)])

#V. Show the box plots for columns: “Age” and “Income”
boxplot(md$Age )
boxplot(md$Income)


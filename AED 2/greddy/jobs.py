
 
def printJobScheduling(arr, t):
 
    # length of array
    n = len(arr)
 
    # Sort all jobs according to
    # decreasing order of profit
    for i in range(n):
        for j in range(n - 1 - i):
            if arr[j][2] < arr[j + 1][2]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
 
    # To keep track of free time slots
    result = [False] * t
 
    # To store result (Sequence of jobs)
    job = ['-1'] * t
 
    # Iterate through all given jobs
    for i in range(len(arr)):
 
        # Find a free slot for this job
        # (Note that we start from the
        # last possible slot)
        for j in range(min(t - 1, arr[i][1] - 1), -1, -1):
 
            # Free slot found
            if result[j] is False:
                result[j] = True
                job[j] = arr[i][0]
                break
 
    # print the sequence
    print(job)
 
 
# Driver's Code
# Each job is represented as a tuple (job_name, deadline, profit)
jobs = [
    ('Job1', 4, 70),
    ('Job2', 2, 50),
    ('Job3', 4, 30),
    ('Job4', 3, 40),
    ('Job5', 1, 60),
]

# Number of time slots
time_slots = 4

# Call the function with the array and time slots
printJobScheduling(jobs, time_slots)
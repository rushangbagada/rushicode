#  Write a function called make_album() that builds a dictionary describing a music album. 
# The function should take in an artist name and an album title, and it should return a 
# dictionary containing these two pieces of information. Use the function to make three 
# dictionaries representing different albums. Print each return value to show that the 
# dictionaries are storing the album information correctly.  
# Add an optional parameter to make_album() that allows you to store the number of tracks 
# on an album. If the calling line includes a value for the number of tracks, add that value to 
# the album’s dictionary. Make at least one new function call that includes the number of 
# tracks on an album.

def make_album(artist, album):
    album_dict = {"artist": artist, "album": album}
    return album_dict

def make_album_tracks(artist, album, tracks=0):
    album_dict = {"artist": artist, "album": album}
    if tracks:
        album_dict["tracks"] = tracks
    return album_dict   
# Test the function with three different albums
print(make_album("Taylor Swift", "Red"))
print(make_album("Arijit Singh", "Tum Hi Ho"))
print(make_album_tracks("Ed Sheeran", "Shape of You", 12))

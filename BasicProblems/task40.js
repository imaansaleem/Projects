function make_album(artist_name, album_title, number_of_tracks=0){
    let music_album={
        name: artist_name,
        title: album_title,
        tracks: number_of_tracks,
    };
    return music_album;
}

let album=make_album("Arcade Fire","Funeral");
console.log(album);
album=make_album("Rufus","Ask Rufus");
console.log(album);
album=make_album("Marvin Gaye","Here, My Dear");
console.log(album);
album=make_album("Bonnie Raitt","Nick of Time",8);
console.log(album);

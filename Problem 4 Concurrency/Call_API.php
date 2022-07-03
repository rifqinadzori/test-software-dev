<?php

function http_request($url){
    // persiapkan curl
    $ch = curl_init(); 

    // set url 
    curl_setopt($ch, CURLOPT_URL, $url);
    
    // set user agent    
    curl_setopt($ch,CURLOPT_USERAGENT,'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13');

    // return the transfer as a string 
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 

    // $output contains the output string 
    $output = curl_exec($ch); 

    // tutup curl 
    curl_close($ch);      

    // mengembalikan hasil curl
    return $output;
}

$profile = http_request("https://data.gov.sg/api/action/datastore_search?resource_id=eb8b932c-503c-41e7-b513-114cffbe2338&limit=660");

// ubah string JSON menjadi array
$profile = json_decode($profile, TRUE);

$hasil_API = $profile['result']['records'];

// buka file
$fp = fopen('data_graduate.csv', 'w');

$header = false;

// Looping isi tabel csv
foreach ($hasil_API as $fields) {
	if (empty($header))
    {
        $header = array_keys($fields);
        fputcsv($fp, $header);
        $header = array_flip($header);
    }
    //fputcsv($fp, $fields);
	fputcsv($fp, array_merge($header, $fields));
}
  
fclose($fp);

echo "<pre>";
//print_r($hasil_API);
//print_r($profile);
echo "</pre>";
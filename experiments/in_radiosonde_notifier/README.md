# Experiments in radiosonde notifier

Aim: get a notification of the predicted radiosonde path and landing as well as
the live prediction, path and landing.

## Design

Attempt a generic design for
1. on a CRON time schedule
1. perform an API call
1. apply a processor
1. decide what action to take - nothing, update, notify
1. notify action

In detail

- input launch zone - Melbourne launch zone
    ```json
    {latitude: -37.6697, longitude: 144.831}
    ```
- input notification medium - SMS, Email, PushNotification via PWA
  and something like firebase?
- input frequencey - once an hour, CRON format?
- input GPS lookup API
    - https://dash.geocod.io/ - 2,500 lookups a day?,
      unfortunately after some testing it seems it is of no use
      for doing reverse lookups in Victoria
      ```ruby
      require 'geocodio'
      geocodio = Geocodio::Client.new(
        ENV.fetch('GEOCODIO_API_KEY'))
     addresses = geocodio.reverse_geocode(['-37.6697,144.831'])
     ```
    - grab a database of Australian postcodes with lat/long
        -from https://gist.github.com/randomecho/5020859
    - convert to CSV
    - do a lookup with minimum distance using formula
    ```
    =acos(
        sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(lon2-lon1)
    )*6371
    # (6371 is Earth radius in km.)
    ```
- input predictor - https://predict.sondehub.org/
    - capture image
    - extract GPS - lookup using GPS lookup API
- input fetcher
    - https://radiosondy.info/sonde_table.php?startplace=Melbourne+%28AU%29&table=startplace
- input processor for live prediction, path, landing
    ```js
    Array.from(document.querySelectorAll("#list_container tr"))[1].textContent

    => '\nV2431374\nRS41\n2024-03-10 01:17:30\n-37.7767\n145.428\n172 °\n31 km/h\n222 m\n-6.7 m/s\n401.500 MHz\nMount Evelyn (AU)\n14522.66 km\nUNKNOWN\n'

    Array.from(document.querySelectorAll("#list_container tr td a"))[1]
    => <a href="sonde.php?sondenumber=V2431366">V2431366</a>

    # follow link
    # https://radiosondy.info/sonde_archive.php?sondenumber=V2431374
    document.querySelectorAll("#map")
    # save as image
    # send
    ```

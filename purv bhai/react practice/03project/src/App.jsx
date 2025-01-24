import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  let [color, setcolor] = useState("blue")

  return (

    <div className=" h-screen w-screen duration-5000"
      style={{ backgroundColor: color }}
    >
      <div className="fixed  flex flex-wrap justify-center bottom-12 inset-x-0 py-2">
        <div className="flex flex-wrap justify-center gap-4 shadow-lg bg-white px-3 py-2 rounded-3xl">
          <button
            onClick={() => setcolor("red")}
            className="outline-none px-4 py-1 text-white rounded-full bg-red-700 shadow-lg"
            
          >Red</button>

          <button
            onClick={() => setcolor("blue")}
            className=" rounded-full px-4 py-2 text-white shadow-2xl outline-none"
            style={{ backgroundColor: "blue" }}
          >blue</button>
          <button
            onClick={() => setcolor("purple")}
            className=" rounded-full px-4 py-2 text-white shadow-2xl outline-none"
            style={{ backgroundColor: "purple" }}
          >purple</button>
          <button
            onClick={() => setcolor("green")}
            className=" rounded-full px-4 py-2 text-white shadow-2xl outline-none"
            style={{ backgroundColor: "green" }}
          >green</button>
          <button
            onClick={() => setcolor("#1f1f1f")}
            className=" rounded-full px-4 py-2 text-white shadow-2xl outline-none"
            style={{ backgroundColor: "#1f1f1f" }}
          >black</button>
          <button
            onClick={() => setcolor("grey")}
            className=" rounded-full px-4 py-2 text-white shadow-2xl outline-none"
            style={{ backgroundColor: "grey" }}
          >grey</button>
          <button
            onClick={() => setcolor("orange")}
            className=" rounded-full px-4 py-2 text-white shadow-2xl outline-none"
            style={{ backgroundColor: "orange" }}
          >orange</button>

        </div>
      </div>
    </div>

  )
}

export default App

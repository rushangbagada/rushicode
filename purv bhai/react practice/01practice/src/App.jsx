import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  let [count, setcount] = useState(0)

  const add = () => {
    setcount(count + 1)
  }
  const min = () => {
    if (count > 0) {
      setcount(count - 1)
    }
  }

  return (
    <>
      <h1>chai aur code</h1>
      <h1>counter value: {count}</h1>

      <button onClick={add}>add {count}</button><br />
      <button onClick={min}>minus {count}</button>

    </>
  )
}

export default App
